var maxTry= 3;
function validate(){
var username = document.getElementById("username").value;
var password = document.getElementById("password").value;
var err=document.getElementById("error").innerHTML;

if(username==""){alert("User Name Should not be empty");} 
if(password==""){alert("Password should not be empty");}


if ( username == "nativeself" && password == "nativeself"){

window.alert("Log in successful!");
window.location = "features screen.html";
return false;
}

//giving 3 chances to user 
else{
maxTry--;
document.getElementById("error").innerHTML="<br>Incrorrect username and password"+"<br>You have left"+maxTry+" attempt.";
if(maxTry== 0){
document.getElementById("username").disabled = true;
document.getElementById("password").disabled = true;
document.getElementById("submit").disabled = true;
return false;}
}
}


//CAPTCHA
//This function changes the captcha whenever the page is reloaded
function ChangeCaptcha() {
    var chars = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXTZabcdefghiklmnopqrstuvwxyz"; 
 
    var string_length = 6; 

    var ChangeCaptcha = '';
    for (var i=0; i<string_length; i++) {
        var rnum = Math.floor(Math.random() * chars.length); //Random number is being generated
        ChangeCaptcha += chars.substring(rnum,rnum+1);
    }
    
    document.getElementById('randomchar').value = ChangeCaptcha; 
}

//Function to check if the captcha matches or not
function check() { 
    if(document.getElementById('inputCaptcha').value == document.getElementById('randomchar').value ) {  
        validate();    
    }
    else {
        alert('Please re-check the captcha');
    }
}
