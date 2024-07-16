const wrapper = document.querySelector('.wrapper'),
form = wrapper.querySelectorAll('.form'),
submitInput = form[0].querySelector('input[type="submit"]');
function getDataForm(){
        //e.preventDefault();
        var formData = new FormData(form[0]);
        var a= formData.get('name');
        var b= formData.get('mail');
        var c= formData.get('password');
    }
//document.addEventListener('DOMContentLoaded', function(){
submitInput.addEventListener('click', getDataForm);
//},false);
function revealmessage(){
    document.getElementById("hiddenmessage").style.display='block';
}