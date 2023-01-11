/*
Name: Ghazi Najeeb Al-Abbar
ID: 2181148914
File Name: Pharmacist_Main_Page.js
Phase 2
*/

var CartItems = [];

//Medicine constructor
function Med(Name, UnitPrice, Spec, Qty, TotalCost) {
  this.name = Name;
  this.unitPrice = UnitPrice;
  this.spec = Spec;
  this.qty = Qty;
  this.total = TotalCost;
}

//Extracts the id number from a given html tag id
function getIdNumber(id) {
  var Size = id.length - 1;
  var Num = parseInt(id[Size]);
  var AddZero = 10;

  Size--;

  while (id[Size] != "-") {
    Num = parseInt(id[Size]) * AddZero + Num;

    Size--;
    AddZero *= 10;
  }

  return Num;
}

function AddtoCart(event, MedName, UnitPrice, qty, Medid) {
  var ID = getIdNumber(event.id);

  var Quantity = parseInt(document.getElementById("qty-" + ID).value);

  if (Quantity > parseInt(qty)) {
    window.alert(
      "You have requested " +
        Quantity +
        " units of " +
        MedName +
        " When there is only " +
        qty +
        "Left.."
    );
  } else {
    const xmlhttp = new XMLHttpRequest();

    xmlhttp.open(
      "GET",
      "./php/AddToCart.php?med-name=" +
        MedName +
        "&unit-price=" +
        UnitPrice +
        "&med-qty=" +
        Quantity +
        "&med-id=" +
        Medid
    );
    xmlhttp.send(null);

    var Avail = document.getElementById("avail-" + ID);
    Avail.innerHTML = qty - Quantity;
  }
}
