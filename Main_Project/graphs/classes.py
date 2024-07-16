import os
import random
# Path to the directory containing the class folders
dataset_dir = 'dataset/farm_pests'

# List all class folders in the dataset directory
class_folders = [folder for folder in os.listdir(dataset_dir) if os.path.isdir(os.path.join(dataset_dir, folder))]

# Randomly select one image from each class

import matplotlib.pyplot as plt
import matplotlib.image as mpimg

# Define the number of rows and columns for the grid
num_rows = 7
num_cols = 3

selected_images = ['dataset/farm_pests/Fruit Flies/Image_38.jpg', 'dataset/farm_pests/sawfly/jpg_40.jpg', 'dataset/farm_pests/armyworm/jpg_15 - Copy (2).jpg', 'dataset/farm_pests/Thrips/Image_55.jpg', 'dataset/farm_pests/Western Corn Rootworms/Image_88 (copy).jpg', 'dataset/farm_pests/Corn Borers/Image_55 (3rd copy).jpg', 'dataset/farm_pests/Brown Marmorated Stink Bugs/Image_68 (copy).jpg', 'dataset/farm_pests/Corn Earworms/Image_17.jpg', 'dataset/farm_pests/beetle/jpg_18 - Copy (copy).jpg', 'dataset/farm_pests/Cabbage Loopers/Image_23 (3rd copy).jpg', 'dataset/farm_pests/Tomato Hornworms/Image_84 (another copy).jpg', 'dataset/farm_pests/Colorado Potato Beetles/Image_102.jpg', 'dataset/farm_pests/mites/jpg_18 - Copy (4).jpg', 'dataset/farm_pests/Spider Mites/Image_111.jpg', 'dataset/farm_pests/grasshopper/jpg_10.jpg', 'dataset/farm_pests/aphids/jpg_50 - Copy (4).jpg', 'dataset/farm_pests/Stem Borer/jpg_49 (copy).jpg', 'dataset/farm_pests/bollworm/jpg_95.jpg', 'dataset/farm_pests/Fall Armyworms/Image_19 (3rd copy).jpg', 'dataset/farm_pests/Africanized Honey Bees (Killer Bees)/Image_90 (another copy).jpg', 'dataset/farm_pests/Citrus Canker/Image_71 (another copy).jpg']
print(selected_images)

# Create a new figure
plt.figure(figsize=(6, 8))

# Plot each image in a grid
for i in range(min(len(selected_images), num_rows * num_cols)):
    # Load and plot the image
    img = mpimg.imread(selected_images[i])
    plt.subplot(num_rows, num_cols, i + 1)
    plt.imshow(img)
    plt.axis('off')

    plt.text(0.5, -0.15, str(i+1), fontsize=12, ha='center', transform=plt.gca().transAxes)

# Adjust layout and display the plot
plt.tight_layout()
plt.show()