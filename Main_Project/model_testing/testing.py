import tensorflow as tf
import matplotlib.pyplot as plt
from tensorflow import keras
from tensorflow.keras.preprocessing import image
import numpy as np

# Step 1: Load the Model
model = tf.saved_model.load('/home/basheer/Desktop/^/Main_Project/model_testing/model/Model')
inference = model.signatures["serving_default"]

# Step 2: Load and Preprocess Image Data
# Assuming you have image files and you want to make predictions on each of them
image_paths = ['/home/basheer/Desktop/^/Main_Project/dataset/farm_pests/Western Corn Rootworms/Image_119.jpg']  # List of paths to your image files
actual_labels = [path.split('/')[7] for path in image_paths]

# Preprocess the images
def preprocess_image(image_path):
    img = image.load_img(image_path, target_size=(224, 224))  # Specify the target size
    img_array = image.img_to_array(img)
    img_array = np.expand_dims(img_array, axis=0)  # Add batch dimension
    return img_array

# Function to plot image and predicted label
def plot_image_with_label(image_path, actual_label, predicted_label):
    img = image.load_img(image_path)
    color = "red"
    if actual_label == predicted_label:
        color = "green"
        
    plt.imshow(img)
    plt.axis('off')
    plt.title('Actual Label: ' + actual_label + '\nPredicted Label: ' + predicted_label, color = color)

# Iterate through each image path, preprocess the image, and make predictions
for i,image_path in enumerate(image_paths):
    # Step 3: Predict
    plt.subplot(1, len(image_paths), i+1)
    img_array = preprocess_image(image_path)
    #pred = model.predict(img_array)
    pred = inference(tf.constant(img_array))
    
    pred = np.argmax(pred)

    # Map the label
    labels = (train_images.class_indices)
    labels = dict((v,k) for k,v in labels.items())
    pred = [labels[k] for k in pred]
    
    plot_image_with_label(image_path,actual_labels[0], pred[0])
    
    #print(pred)
