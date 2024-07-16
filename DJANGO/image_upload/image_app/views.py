from django import template
from django.shortcuts import render
from django.http import HttpResponse
from django.template import loader
from .models import pict
from django.shortcuts import redirect

def view(request):
    allimages = pict.objects.all()  
    return render(request, 'picture.html',{'images' : allimages})
'''
def insert(request):

    if request.method == 'POST':
        if request.POST.get('filename'):
            form = pict()
            form.image = request.POST.get('filename')
            form.save()
        
        return render(request,'get_file.html')
    else:
        return render(request,'get_file.html')
'''