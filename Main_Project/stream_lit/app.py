import streamlit as st
from PIL import Image

import tensorflow as tf
import matplotlib.pyplot as plt
from tensorflow import keras
from tensorflow.keras.preprocessing import image    
import numpy as np
import google.generativeai as genai
import matplotlib.pyplot as plt

model = tf.saved_model.load('/home/basheer/Desktop/^/Main_Project/model_testing/Model')

classes = { 0 : 'Africanized Honey Bees (Killer Bees)',
            1 : 'Brown Marmorated Stink Bugs', 
            2 : 'Cabbage Loopers', 
            3 : 'Citrus Canker', 
            4 : 'Colorado Potato Beetles', 
            5 : 'Corn Borers', 
            6 : 'Corn Earworms', 
            7 : 'Fall Armyworms', 
            8 : 'Fruit Flies', 
            9 : 'Spider Mites', 
            10 : 'Stem Borer', 
            11 : 'Thrips', 
            12 : 'Tomato Hornworms', 
            13 : 'Western Corn Rootworms', 
            14 : 'aphids', 
            15 : 'armyworm', 
            16 : 'beetle', 
            17 : 'bollworm', 
            18 : 'grasshopper', 
            19 : 'mites', 
            20 : 'sawfly'
        }


# Preprocess the images
def preprocess_image(image_path):
    img = image.load_img(image_path, target_size=(224, 224))  # Specify the target size
    img_array = image.img_to_array(img)
    img_array = np.expand_dims(img_array, axis=0)  # Add batch dimension
    return img_array

def prediction(image):
    img_array = preprocess_image(image)
    #pred = model.predict(img_array)
    
    #pred = np.argmax(pred,axis=1)

    inference_func = model.signatures['serving_default']
    # Run inference
    output = inference_func(tf.constant(img_array))
    # Access the output tensors and process them as needed
    predictions = output['dense_11'].numpy()
    
    predicted_class = classes[np.argmax(predictions)]

    print(predictions)
    
    col1.write(f' Predicted pest : {predicted_class} ')

    # Used to securely store your API key
    # from google.colab import userdata

    genai.configure(api_key="AIzaSyBVLrVRDy4ZL4a20oMoLd6Yofnv62enW4E")

    api = genai.GenerativeModel('gemini-pro')
    response = api.generate_content(f' The crop pest {predicted_class} control remedies for agriculture field and its pestisides')

    # Add the horizontal line
    st.write("<hr>", unsafe_allow_html=True)
    st.write(f"<center> Remedies </center>", unsafe_allow_html=True)
    st.write(f'{response.text}')



def fix_image(upload):
    image = Image.open(upload)
    col1.write("Pest Image :camera:")
    col1.image(image)

    img = np.array(image)

    grayscale_img = np.mean(img, axis=-1)

    height, width = image.size

    fig, ax = plt.subplots(figsize=(4, 6))
    heatmap = ax.imshow(grayscale_img, cmap='viridis', interpolation='nearest')

    ax.axis('off')

    fig.canvas.draw()
    heatmap_img = np.frombuffer(fig.canvas.tostring_rgb(), dtype=np.uint8)
    heatmap_img = heatmap_img.reshape(fig.canvas.get_width_height()[::-1] + (3,))

    non_empty_rows = np.where(~np.all(heatmap_img == 255, axis=1))[0]
    non_empty_cols = np.where(~np.all(heatmap_img == 255, axis=0))[0]

    # Trim the heatmap image
    trimmed_img = heatmap_img[non_empty_rows.min():non_empty_rows.max() + 1,
                              non_empty_cols.min():non_empty_cols.max() + 1]
    # Display the heatmap in Streamlit
    col2.write("Heatmap")
    col2.image(trimmed_img, use_column_width=True)

    prediction(upload)


st.set_page_config(layout="wide", page_title="Pest Control")
st.title('Pest detection and remedies')
#st.write("helloo")

col1, col2 = st.columns(2)
st.sidebar.write("## Upload")
my_upload = st.sidebar.file_uploader("Upload an image", type=["png", "jpg", "jpeg"])

if my_upload is not None:
    fix_image(upload=my_upload)
#else:
#    fix_image("./zebra.jpg")