function showBMI(){

    var weight = parseFloat(document.getElementById("weight").value);
    var height = parseFloat(document.getElementById("height").value);
    var BMIdiv = document.getElementById("bmi");

    console.log(weight);
    console.log(height);

    var BMI = weight / (height * height);
    var Res = "";

    console.log(BMI);

    if (BMI < 18.5){

        Res += "underweight";
    }

    else if (BMI >= 18.5 && BMI <= 24.9){

        Res += "normal";
    }

    else if (BMI >= 25 && BMI <= 29.9){

        Res += "overweight";
    }

    else{

        Res += "Obese";
    }

    BMIdiv.innerHTML = "<br /><br />" + "You are " + Res + "<br />";
}