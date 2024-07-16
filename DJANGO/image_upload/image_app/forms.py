from django import forms
from .models import pict

class MyForm(forms.ModelForm):
  class Meta:
    model = pict
    fields = ["name"]
    labels = {'name': "Name"}