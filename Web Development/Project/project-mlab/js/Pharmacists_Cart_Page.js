/*
Name: Ghazi Najeeb Al-Abbar
ID: 2181148914
File Name: Pharmacist_Cart_Page.js
Phase 2
*/

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

function Decrement(event, name, qty) {
  qty = parseInt(qty);
  qty--;

  if (qty == 0) {
    var Row = document.getElementById("Cart-Item-" + getIdNumber(event.id));
    Row.remove();
  } else {
    Row.innerHTML = qty.toString();
  }

  const xmlhttp = new XMLHttpRequest();

  xmlhttp.onreadystatechange = function () {
    if (this.readyState == 4 && this.status == 200) {
      var response = this.responseText;

      var qtyInCart = document.getElementById("qty-" + getIdNumber(event.id));
      qtyInCart.innerHTML = qty;
    }
  };

  xmlhttp.open(
    "GET",
    "./php/Actions.php?name=" + name + "&qty=" + qty + "&action=decr"
  );
  xmlhttp.send();
}

function Increment(event, name, qty) {
  const xmlhttp = new XMLHttpRequest();

    xmlhttp.onreadystatechange = function() {
        
      if (this.readyState == 4 && this.status == 200) {
        var response = this.responseText;

        if (respone === '0'){

            window.alert("You have all units of " + name + " in your cart..");
        }
        else if (response === '1'){

            var qtyInCart = document.getElementById("qty-" + getIdNumber(event.id));
            qtyInCart.innerHTML = qty + 1;
        }
      }

      else{

        window.alert("Something went wrong..");
      }
    };


  var param = encodeURIComponent(name);
  xmlhttp.open(
    "GET",
    "./php/Actions.php?name=" + param + "&qty=" + qty + "&action=incr"
  );
  xmlhttp.open("GET", "../php/Actions.php?name=" + name + "&qty=" + qty + "&Eleid=qty-" + getIdNumber(event.id) + "&action=incr");
  xmlhttp.send();
}

function Remove(event, name) {
  var Row = document.getElementById("Cart-Item-" + getIdNumber(event.id));
  Row.remove();

  const xmlhttp = new XMLHttpRequest();

  xmlhttp.open(
    "GET",
    "./php/Actions.php?name=" + name + "&qty=" + qty + "&action=rmv"
  );
  xmlhttp.send();
}

function isCartEmpty() {
  const xmlhttp = new XMLHttpRequest();

  xmlhttp.onreadystatechange = function () {
    if (this.readyState == 4 && this.status == 200) {
      response = this.responseText;

      if (response === "0") {
        window.alert("The cart is empty!");
      } else if (response === "1") {
        location.replace("./Customer_Data.php");
      }
    }
  };

  xmlhttp.open("GET", "./php/Actions.php?action=empty");
  xmlhttp.send(null);
}
