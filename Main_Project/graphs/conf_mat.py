# Import Data Science Libraries
import numpy as np
import pandas as pd
import tensorflow as tf
from sklearn.model_selection import train_test_split

from keras_preprocessing.image import ImageDataGenerator

# System libraries
from pathlib import Path
import os.path

# Metrics
from sklearn.metrics import classification_report, confusion_matrix

# Import series of helper functions for our notebook
from helper_functions import create_tensorboard_callback, make_confusion_matrix, plot_loss_curves, unzip_data, compare_historys, walk_through_dir, pred_and_plot

BATCH_SIZE = 32
IMAGE_SIZE = (300, 300)

# Walk through each directory
dataset = "/home/basheer/Desktop/^/Main_Project/dataset/farm_pests"
walk_through_dir(dataset)

image_dir = Path(dataset)

# Get filepaths and labels
filepaths = list(image_dir.glob(r'**/*.JPG')) + list(image_dir.glob(r'**/*.jpg')) + list(image_dir.glob(r'**/*.png')) + list(image_dir.glob(r'**/*.png'))

labels = list(map(lambda x: os.path.split(os.path.split(x)[0])[1], filepaths))

filepaths = pd.Series(filepaths, name='Filepath').astype(str)
labels = pd.Series(labels, name='Label')

# Concatenate filepaths and labels
image_df = pd.concat([filepaths, labels], axis=1)

# Separate in train and test data
train_df, test_df = train_test_split(image_df, test_size=0.2, shuffle=True, random_state=1)

train_generator = ImageDataGenerator(
    preprocessing_function=tf.keras.applications.mobilenet_v3.preprocess_input,
    validation_split=0.2
)

test_generator = ImageDataGenerator(
    preprocessing_function=tf.keras.applications.mobilenet_v3.preprocess_input
)

# Split the data into three categories.
train_images = train_generator.flow_from_dataframe(
    dataframe=train_df,
    x_col='Filepath',
    y_col='Label',
    target_size=(224, 224),
    color_mode='rgb',
    class_mode='categorical',
    batch_size=32,
    shuffle=True,
    seed=42,
    subset='training'
)

val_images = train_generator.flow_from_dataframe(
    dataframe=train_df,
    x_col='Filepath',
    y_col='Label',
    target_size=(224, 224),
    color_mode='rgb',
    class_mode='categorical',
    batch_size=32,
    shuffle=True,
    seed=42,
    subset='validation'
)

test_images = test_generator.flow_from_dataframe(
    dataframe=test_df,
    x_col='Filepath',
    y_col='Label',
    target_size=(224, 224),
    color_mode='rgb',
    class_mode='categorical',
    batch_size=32,
    shuffle=False
)

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

actual_labels = []

for i in test_images.labels:
    actual_labels.append(classes[i])


from tensorflow.keras.preprocessing import image

# Define preprocess_image function
def preprocess_image(image_path):
    img = image.load_img(image_path, target_size=(224, 224))  # Specify the target size
    img_array = image.img_to_array(img)
    img_array = np.expand_dims(img_array, axis=0)  # Add batch dimension
    return img_array


# Load the saved model
model_path = '/home/basheer/Desktop/^/Main_Project/model_testing/Model'
model = tf.saved_model.load(model_path)

predicted_class = []

# Loop through test images
for img_path in test_images.filepaths:
    img_array = preprocess_image(img_path)

    inference_func = model.signatures['serving_default']
    # Run inference
    output = inference_func(tf.constant(img_array))
    # Access the output tensors and process them as needed
    predictions = output['dense_11'].numpy()
    
    predicted_class.append(classes[np.argmax(predictions)])

print(classification_report(actual_labels, predicted_class))


# Map the label
#labels = (train_images.class_indices)
#labels = dict((v,k) for k,v in labels.items())
#
#make_confusion_matrix(actual_labels, predicted_class, list(labels.values()))
