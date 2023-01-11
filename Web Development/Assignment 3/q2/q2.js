// Name: Ghazi Najeeb Al-Abbar
// ID: 2181148914
// Assignemnt 3
// filename: q2.js

//Global Vars
var CarList = [];
var Total;
var Max = 0;
var Min = 1000000;
var Avg;

//Gets input from the user
Total = window.prompt("Enter how many cars you want:");
Total = parseInt(Total);

//Car constructor
function car(Model, Brand, Price){

	this.model = Model;
	this.brand = Brand;
	this.price = Price;
}

//Initialises the document from the given data (Total)
function INIT(){

	var form = document.getElementById("form");
	var str = "";

	for (var i = 0; i < Total; i++){

		str +=
		`
			<p>
				Car Model: <input type="text" id="model` + (i + 1) + `" class="txtBox">
				Car Brand: <input type="text" id="brand` + (i + 1) + `" class="txtBox">
				Car Price: <input type="text" id="price` + (i + 1) + `" class="txtBox">
			</p>
		`;
	}

	str += 
	`
		<button type="button" onclick="VIEW()">View</button>
	`;

	form.innerHTML = str;
}

//Button action - prints a table with all the user entered data, plus the min, max prices and the average
function VIEW(){

	var table = document.getElementById("table");
	var str = "";

	Avg = 0;

	for (var i = 0; i < Total; i++){

		var model = document.getElementById("model" + (i + 1)).value;
		var brand = document.getElementById("brand" + (i + 1)).value;
		var price = document.getElementById("price" + (i + 1)).value;

		CarList[i] = new car(model, brand, price);

		if (parseInt(price) > Max){

			Max = parseInt(price);
		}

		if (parseInt(price) < Min){

			Min = parseInt(price);
		}

		Avg += parseInt(price);
	}

	Avg /= Total;

	str += 
	`
		<table width="500" height="` + (100 * Total + 100) + `">
			<tr>
				<th>#</th>
				<th>Model</th>
				<th>Brand</th>
				<th>Price</th>
			</tr>
	`;

	for (var i = 0; i < Total; i++){

		str += 
		`
			<tr>
				<td>` + (i + 1) + `</td>
				<td>` + CarList[i].model + `</td>
				<td>` + CarList[i].brand + `</td>
				<td>` + CarList[i].price + `</td>
			</tr>
		`;
	}

	str +=
	`
		<tr>
			<td>Max Price</td>
			<td>` + Max + `</td>
			<td>Min Price</td>
			<td>` + Min + `</td>
			<td>Average Price</td>
			<td>` + Avg + `</td>
		</tr>
		</table>
	`;

	table.innerHTML = str;
}

//calls the INIT function as soon as the page loads
window.addEventListener("load", INIT);