/*
  login.js
  Hassan Khalaf - 2192131028
  Phase 2
*/

// login.html | login.js
let email = null;
let password = null;
let remember = null;

// en-de crypt
const encrypt = (text) => {
  return CryptoJS.enc.Base64.stringify(CryptoJS.enc.Utf8.parse(text));
};

const decrypt = (data) => {
  return CryptoJS.enc.Base64.parse(data).toString(CryptoJS.enc.Utf8);
};

// email checking
function ValidateEmail(mail) {
  if (/^\w+([\.-]?\w+)*@\w+([\.-]?\w+)*(\.\w{2,3})+$/.test(mail)) {
    return true;
  }
  return false;
}

//passwrod checking
function CheckPassword(inputtxt) {
  var paswd = /^(?=.*[0-9])(?=.*[!@#$%^&*])[a-zA-Z0-9!@#$%^&*]{7,15}$/;
  if (inputtxt.match(paswd)) return true;
  else return false;
}
// for starting page
function start() {
  console.log("Hello World");
  console.log(
    "Warning: This page is not supposed to be opened. If someone is asking you to open this, please know that he might try to get your login information."
  );
  // set the elements
  email = document.getElementById("loginEmail");
  password = document.getElementById("loginPassword");
  remember = document.getElementById("loginSave");

  // check of remeber from local storage exist
  if (localStorage.getItem("remember") != null) {
    // if yes, then fill the form
    remember.checked = true;
    email.value = localStorage.getItem("email");
    password.value = decrypt(localStorage.getItem("password"));
  }
}

// on login event
function login() {
  if (!ValidateEmail(email.value)) {
    Swal.fire("Error!", "Your email is not valid..", "error");
    return;
  }

  if (!CheckPassword(password.value)) {
    Swal.fire(
      "Error!",
      "Input Password and Submit [7 to 15 characters which contain at least one numeric digit and a special character]",
      "error"
    );
    return;
  }
  var flag; //checker

  // set flag (static wo database)
  // check the vlaues of the form and set the value
  email.value == "test@gmail.com" && password.value == "test1234A!"
    ? (flag = true)
    : (flag = false);

  // if the form information is correct
  if (flag) {
    Swal.fire("Welcome!", "You will be in the home page now..", "success");
    // if remeber checkbox is checked, save the information in the local storage
    if (remember.checked) {
      localStorage.setItem("remember", "yes");
      localStorage.setItem("email", email.value);
      let passwordBytes = encrypt(password.value);
      localStorage.setItem("password", passwordBytes);
    } else {
      localStorage.clear();
    }
  } // if form information is not correct
  else Swal.fire("Why?!", "One or two of the information is wrong..", "error");
}

// on load start function start
window.addEventListener("load", start, false);
