var N = window.prompt("Enter a Positive Number:");

while (N <= 0){

	N = window.prompt("Enter a Positive Number:");
}

var Form_List = [];
var Total;
const Width = 800;
var Height = 100; 
var isChanged = false;
const buttons = 
`
					<button class="btn" id="new-btn" onclick="NEW()">New</button>
					<button type="button" class="btn" id="add-btn" onclick="ADD()">Add</button>
					<button class="btn" id="delete-btn" onclick="DELETE()">Delete</button>
`

Total = parseInt(N);

function Car(Brand, Model, Price){

	this.brand = Brand;
	this.model = Model;
	this.price = Price;
}


function ADD(){

	if (isChanged){
		Height = 100 * Total;
		isChanged = false;
	}

	var divStr = "";
	var tdiv = document.getElementById("tdiv");

	for (var i = 0; i < Total; i++){

		var brand = document.getElementById("brand" + (i + 1)).value;
		var model = document.getElementById("model" + (i + 1)).value;
		var price = document.getElementById("price" + (i + 1)).value;
		Form_List[i] = new Car(brand, model, price);
	}

	divStr += `<table height="` + Height + `" width="` + Width + `"><th><td>Car Brand</td><td>Model</td><td>Price</td></th>`;

	for (var i = 0; i < Total; i++){

		divStr += "<tr><td>" + (i + 1) + "</td><td>" + Form_List[i].brand + "</td>"
				+ "<td>" + Form_List[i].model + "</td><td>" + Form_List[i].price + "</td></tr>";
	}

	divStr += "</table>";

	tdiv.innerHTML = divStr;
	
}

function NEW(){

	Total++;
	var form_str = "";
	var form = document.getElementById("form");

	for (var i = 0; i < Total; i++){

		form_str += "<p>Car Brand:<input type=\"text\" class=\"text-box\" id=\"brand" + (i + 1) + "\">" + "Model:<input type=\"text\" class=\"text-box\" id=\"model" + (i + 1) + "\">"
					+ "Price:<input type=\"text\" class=\"text-box\" id=\"price" + (i + 1) + "\">" + "</p>";
	}

	form_str += buttons

	form.innerHTML = form_str;

	isChanged = true;
}

function DELETE(){

	Total--;
	var form_str = "";
	var form = document.getElementById("form");

	for (var i = 0; i < Total; i++){

		form_str += "<p>Car Brand:<input type=\"text\" class=\"text-box\" id=\"brand" + (i + 1) + "\">" + "Model:<input type=\"text\" class=\"text-box\" id=\"model" + (i + 1) + "\">"
					+ "Price:<input type=\"text\" class=\"text-box\" id=\"price" + (i + 1) + "\">" + "</p>";
	}

	form_str += buttons

	form.innerHTML = form_str;

	isChanged = true;
}

function INIT(){

	var form_str = "";
	var form = document.getElementById("form");

	for (var i = 0; i < Total; i++){

		form_str += "<p>Car Brand:<input type=\"text\" class=\"text-box\" id=\"brand" + (i + 1) + "\">" + "Model:<input type=\"text\" class=\"text-box\" id=\"model" + (i + 1) + "\">"
					+ "Price:<input type=\"text\" class=\"text-box\" id=\"price" + (i + 1) + "\">" + "</p>";
	}

	form_str += buttons;

	form.innerHTML = form_str;
}

window.addEventListener("load", INIT, false);