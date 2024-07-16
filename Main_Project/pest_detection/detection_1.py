import detection

results = detection.model.evaluate(detection.test_images, verbose=0)

print("    Test Loss: {:.5f}".format(results[0]))
print("Test Accuracy: {:.2f}%".format(results[1] * 100))

accuracy = detection.history.history['accuracy']
val_accuracy = detection.history.history['val_accuracy']

loss = detection.history.history['loss']
val_loss = detection.history.history['val_loss']

epochs = range(len(accuracy))
detection.plt.plot(epochs, accuracy, 'bo', label='Training accuracy')
detection.plt.plot(epochs, val_accuracy, 'b', label='Validation accuracy')
detection.plt.title('Training and validation accuracy')
detection.plt.legend()
detection.plt.figure()
detection.plt.plot(epochs, loss, 'bo', label='Training loss')
detection.plt.plot(epochs, val_loss, 'b', label='Validation loss')
detection.plt.title('Training and validation loss')
detection.plt.legend()
detection.plt.show()