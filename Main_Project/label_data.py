import os
from typing import Counter
import numpy as np
from PIL import Image
import matplotlib.pyplot as plt

import cv2

def image_to_feature_vector(image_path, target_size=(224, 224)):
    # Load image
    image = cv2.imread(image_path)

    # Resize to target size
    resized_image = cv2.resize(image, target_size)

    # Convert to NumPy array and flatten
    image_array = np.array(resized_image)
    feature_vector = image_array.flatten()

    return feature_vector

# specify the directory where the folders containing the images are located
dataset_dir = '/home/basheer/Desktop/^/Main_Project/dataset/skruruu'

# create a dictionary to store the file names and their corresponding labels
data = []
labels = []
feature_vectors =[]

# iterate through each folder in the dataset directory
for folder in os.listdir(dataset_dir):
    # check if the current directory entry is a directory
    folder_path = os.path.join(dataset_dir,folder)
    if os.path.isdir(folder_path):
        # iterate through each image file in the folder
        for image_file in os.listdir(folder_path):
            # Combine the label and file path to get the full data point
            data_point = os.path.join(folder_path,image_file)

            feature = image_to_feature_vector(data_point)
            # Append the data point,label,feature to the data list
            data.append(data_point)
            labels.append(folder)
            feature_vectors.append(feature)


dic = {}

for i in labels:
    if i in dic.keys():
        dic[i] += 1
    else:
        dic[i] = 1

print(dic)
# Convert the feature and labels lists to numpy arrays
labels = np.array(labels)
feature_vectors = np.array(feature_vectors)


# Print the shape of the data and labels arrays
#print("Shape of feature vector array: ", feature_vectors.shape)
#print("Shape of labels array: ", labels.shape)

#print('Counter({0.0: 50, 1.0: 30})')

from imblearn.over_sampling import SMOTE

# Apply SMOTE to the feature vectors and labels
smote = SMOTE()
synthetic_feature_vectors, synthetic_labels = smote.fit_resample(feature_vectors, labels)

# Visualize synthetic images after SMOTE
num_synthetic_images_to_visualize = 10  # Change this number based on your preference

fig, axes = plt.subplots(1, num_synthetic_images_to_visualize, figsize=(15, 15))

for i in range(-1, -num_synthetic_images_to_visualize -1, -1):
    synthetic_image = synthetic_feature_vectors[i].reshape((224, 224, 3))  # Reshape feature vector to image shape
    plt.imshow(synthetic_image)
    plt.axis('off')
    plt.title(f"Synthetic Image {i+1}")
    plt.show()

