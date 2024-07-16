from django.db import models

# Create your models here.
class pict(models.Model):
    image = models.ImageField(upload_to='image')