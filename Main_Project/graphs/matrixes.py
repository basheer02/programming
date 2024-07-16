# Import Data Science Libraries
import numpy as np
#import pandas as pd
import tensorflow as tf

import os
import random
from tensorflow.keras.preprocessing import image

from sklearn.metrics import classification_report, confusion_matrix

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


def preprocess_image(image_path):
    img = image.load_img(image_path, target_size=(224, 224))  # Specify the target size
    img_array = image.img_to_array(img)
    img_array = np.expand_dims(img_array, axis=0)  # Add batch dimension
    return img_array

# Path to the directory containing the class folders
dataset_dir = 'dataset/farm_pests'

# List all class folders in the dataset directory
class_folders = [folder for folder in os.listdir(dataset_dir) if os.path.isdir(os.path.join(dataset_dir, folder))]

# Randomly select one image from each class
selected_images = []
for class_folder in class_folders:
    class_path = os.path.join(dataset_dir, class_folder)
    # List all image files in the class folder
    image_files = [os.path.join(class_path, file) for file in os.listdir(class_path) if file.endswith(('jpg', 'jpeg', 'png'))]
    # Randomly select one image from this class
    selected_images.extend(image_files)

actual_labels = [path.split('/')[2] for path in selected_images]

model_path = '/home/basheer/Desktop/^/Main_Project/model_testing/Model'
model = tf.saved_model.load(model_path)

predicted_class = []

for img in selected_images:
    img_array = preprocess_image(img)

    inference_func = model.signatures['serving_default']
    # Run inference
    output = inference_func(tf.constant(img_array))
    # Access the output tensors and process them as needed
    predictions = output['dense_11'].numpy()
    
    predicted_class.append(classes[np.argmax(predictions)])


print(classification_report(actual_labels, predicted_class))


'''
# Load the saved model
model_path = '/home/basheer/Desktop/^/Main_Project/model_testing/Model'
model = tf.saved_model.load(model_path)
inference = model.signatures["serving_default"]

# Predict the label of the test_images
pred = inference(tf.constant(test_images))    
pred = np.argmax(pred)

# Map the label
labels = (train_images.class_indices)
labels = dict((v,k) for k,v in labels.items())
pred = [labels[k] for k in pred]

# Display the result
print(f'The first 5 predictions: {pred[:5]}')
'''
