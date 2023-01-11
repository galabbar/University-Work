const regex_name = /^[a-zA-Z\s]*$/;
const regex_email = /^[a-zA-Z0-9]*?@[a-zA-Z0-9]*?\.(com|net|org)$/;
const regex_pass =  /^[A-Z]+[A-Za-z{1,}0-9{1,}\W{1,}]*$/;

var errmsg;

function Name_Match(){

	var name = document.getElementById("name").value;

	if ( !regex_name.test(name) ){

		var name_div = document.getElementById("name-div");

		errmsg = document.createElement("div");
		errmsg.innerText = `your name must contain only letters`;
		errmsg.classList.add("errmsg");

		name_div.insertAdjacentElement("afterend", errmsg);

		return false;
	}

	return true;
}

function Age_Match(){

	var age = parseInt(document.getElementById("age").value);

	if ( age >= 18 && age <= 30)
		return true;

	var age_div = document.getElementById("age-div");

	errmsg = document.createElement("div");
	errmsg.innerText = `your age must be between 18 and 30`;
	errmsg.classList.add("errmsg");

	age_div.insertAdjacentElement("afterend", errmsg);

	return false;
}

function Email_Match(){

	var email = document.getElementById("email").value;

	if ( !regex_email.test(email) ){

		var email_div = document.getElementById("email-div");

		errmsg = document.createElement("div");
		errmsg.innerText = `your email was not correct`;
		errmsg.classList.add("errmsg");

		email_div.insertAdjacentElement("afterend", errmsg);

		return false;
	}

	return true;
}

function Pass_Match(){

	var pass = document.getElementById("pass").value;

	if ( !regex_pass.test(pass) ){

		var pass_div = document.getElementById("pass-div");

		errmsg = document.createElement("div");
		errmsg.innerText = 
		`
			your password must start with a capital letter and at least
			one small letter, one digit, and one special character.
		`;
		errmsg.classList.add("errmsg");

		pass_div.insertAdjacentElement("afterend", errmsg);

		return false;
	}

	return true;
}

function MATCH(){

	Name_Match();
	Age_Match();
	Email_Match();
	Pass_Match();
}