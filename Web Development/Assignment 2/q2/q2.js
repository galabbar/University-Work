// Name: Ghazi Najeeb Al-Abbar
// ID: 2181148914
// Assignment: 2
// File name: q2.js

//Checks if a string is all digits
function isAllNumbers(str){

	var Size = str.length;

	for (var i = 0; i < Size; i++){

		if ( !(str[i] >= '0' && str[i] <= '9') ){

			return false;
		}
	}

	return true;
}

//Checks if the id is all numbers
function CheckID(){

	var id = document.getElementById("id").value;

	if ( !isAllNumbers(id) ){

		var id_div = document.getElementById("id-div");

		id_div.innerHTML = 
		`
			<div class="errmsg">Your id must be all numbers</div>
		`;
	}

	return;
}

//Checks if the age is all numbers and is between 16 and 80
function CheckAGE(){

	var age = document.getElementById("age").value;

	if ( !(isAllNumbers(age)) ){

		var age_div = document.getElementById("age-div");

		age_div.innerHTML = 
		`
			<div class="errmsg">Your age must be a numbers</div>
		`;
	}

	else{

		var age_div = document.getElementById("age-div");

		if ( !(parseInt(age) >= 16 && parseInt(age) <= 80) ){

			age_div.innerHTML = 
			`
				<div class="errmsg">Your age must be between 16 and 80</div>
			`;
		}
	}

	return;
}

//Checks if the password and the confirmation password are equal
function checkPASS(){

	var pass = document.getElementById("pass").value;
	var Confirm = document.getElementById("Cpass").value;

	if ( !(pass === Confirm) ){

		var pass_div = document.getElementById("Cpass-div");

		pass_div.innerHTML = 
		`
			<div class="errmsg">Your passwords have to match</div>
		`;
	}

	return;
}

//Calls all the previous check functions and adds error messages to the html code if necessary
function CheckFields(){

	CheckID();
	CheckAGE();
	checkPASS();
}