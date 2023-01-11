// Name: Ghazi Najeeb Al-Abbar
// ID: 2181148914
// Assignment: 2
// File name: q3.js

var Total = 1;
var isChanged = false;

var Pub_Height;
var Priv_Height;
var PubCount;
var PrivCount;
var PubArr = [];
var PrivArr = [];

function project(Id, _Date, Price){

	this.id = Id;
	this.date = _Date;
	this.price = Price;
}

//Function for the "new" button to add a new form element
function NEW(){

	var form = document.getElementById("form" + Total);
	Total++;

	var str = 
	`
		<div id="form` + Total +`">
			<p>
				Enter your id:
				<input type="text" id="id` + Total +`">
			</p>
			<p>
				Select the date
				<input type="date" id="date` + Total +`">
			</p>
			<p>
				Type:<br /> Private <input type="radio" value="private" name="type` + Total +`" id="type` + Total +`
				" checked> Public <input type="radio" value="public" name="type` + Total +`" id="type` + Total +`">
			</p>
			<p>
				Price:
				<input type="text" id="price` + Total +`">
			</p>
			<hr />
		</div>
	`;

	form.insertAdjacentHTML("afterend", str);

	isChanged = true;

}

//Function for the "add" button to add tables under the form
function ADD(){

	var j = 0;
	var k = 0;

	PubCount = 0;
	PrivCount = 0;

	for (var i = 0; i < Total; i++){

		var id = document.getElementById("id" + (i + 1)).value;
		var date = document.getElementById("date" + (i + 1)).value;
		var type = document.querySelector(`input[name="type` + (i + 1) + `"]:checked`).value;
		var price = document.getElementById("price" + (i + 1)).value;

		if (type === "public"){

			PubArr[j] = new project(id, date, price);
			PubCount++;
			j++;
		}

		else if (type === "private"){

			PrivArr[k] = new project(id, date, price);
			PrivCount++;
			k++;
		}

		else{

			alert("The radio button is not working!!");
		}
	}

	if ( isChanged ){

		Pub_Height = PubCount*100 + 100;
		Priv_Height = PrivCount*100 + 100;
	}

	var Pubstr =
	`
		<caption>Public</caption>
		<table height="` + Pub_Height + `" width="550">
			<tr>
				<th>#</th>
				<th>id</th>
				<th>date</th>
				<th>price</th>
			</tr>
	`;
	var Privstr =
	`
		<caption>Private</caption>
		<table height="` + Priv_Height + `" width="550">
			<tr>
				<th>#</th>
				<th>id</th>
				<th>date</th>
				<th>price</th>
			</tr>
	`;
	var pub = document.getElementById("pub");
	var priv = document.getElementById("priv");

	for (var i = 0; i < PubCount; i++){

		Pubstr +=
		`
			<tr>
				<td>` + (i + 1) + `</td>
				<td>` + PubArr[i].id + `</td>
				<td>` + PubArr[i].date + `</td>
				<td>` + PubArr[i].price + `</td>
			</tr>
		`;
	}
	Pubstr += `</table>`;

	for (var i = 0; i < PrivCount; i++){

		Privstr +=
		`
			<tr>
				<td>` + (i + 1) + `</td>
				<td>` + PrivArr[i].id + `</td>
				<td>` + PrivArr[i].date + `</td>
				<td>` + PrivArr[i].price + `</td>
			</tr>
		`;
	}
	Privstr += `</table>`;

	pub.innerHTML = Pubstr;
	priv.innerHTML = Privstr;
}