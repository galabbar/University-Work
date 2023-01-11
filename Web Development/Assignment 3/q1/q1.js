// Name: Ghazi Najeeb Al-Abbar
// ID: 2181148914
// Assignment 3
// filename: q1.js

//Regex for phone number
var PN_Regex = /^(\(?\+\d{3}\)[-]?)?\d{3}[-]?\d{4}$/;
//Regex for email
var Email_Regex = /^[a-zA-Z0-9~!@#$%^&*_-]*@[a-zA-Z0-9~!@#$%^&*_-]*\.(com|net)$/;

//Checks if the phone number is in the pattern of its regex
function checkPN(){

    var PN = document.getElementById("PN").value;

    //prints error message on the document if the input was false
    if ( !PN_Regex.test(PN) ){

        var PN_div = document.getElementById("PN-div");

        PN_div.innerHTML = 
        `
            <span class="errmsg">
                Your phone number must be in the format of (+###)-###-#### or ###-####
            </span>
        `;
    }

    return;
}

//Checks if the email is in the pattern of its regex
function checkEmail(){

    var email = document.getElementById("email").value;

    //prints error message on the document if the input was false
    if ( !Email_Regex.test(email) ){

        var email_div = document.getElementById("email-div");

        email_div.innerHTML = 
        `
            <span class="errmsg">
                You did not type in a correct email
            </span>
        `;
    }

    return;
}

//Function that checks both email and phone numbers
function Check(){

    checkEmail();
    checkPN();
}