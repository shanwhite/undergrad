// each button has its own function (so +/- x6 = 12 different functions)
// counts must be recorded separately to ensure that each shelf has its own count
// if not the other button on another shelf will just count from where the previous count ended

let sugar_count=0;
document.getElementById("sugar-decrease").onclick = function() {
    // get the value of the count then decrease/increase
    // if not the count used across all functions will affect all the counts in the pyramid
    sugar_count--;
    // set the count to 0 if it is lower than 0 since the min. no. of items on a shelf should be 0
    if (sugar_count<0) {
        sugar_count=0;
    }
    document.getElementById("sugar-count").innerHTML = sugar_count;
}
document.getElementById("sugar-increase").onclick = function() {
    sugar_count++;
    document.getElementById("sugar-count").innerHTML = sugar_count;
}

let fats_count=0;
document.getElementById("fats-decrease").onclick = function() {
    fats_count--;
    if (fats_count<0) {
        fats_count=0;
    }
    document.getElementById("fats-count").innerHTML = fats_count;
}
document.getElementById("fats-increase").onclick = function() {
    fats_count++;
    document.getElementById("fats-count").innerHTML = fats_count;
}

let meat_count=0;
document.getElementById("meat-decrease").onclick = function() {
    meat_count--;
    if (meat_count<0) {
        meat_count=0;
    }
    document.getElementById("meat-count").innerHTML = meat_count;
}
document.getElementById("meat-increase").onclick = function() {
    meat_count++;
    document.getElementById("meat-count").innerHTML = meat_count;
}

let dairy_count=0;
document.getElementById("dairy-decrease").onclick = function() {
    dairy_count--;
    if (dairy_count<0) {
        dairy_count=0;
    }
    document.getElementById("dairy-count").innerHTML = dairy_count;
}
document.getElementById("dairy-increase").onclick = function() {
    dairy_count++;
    document.getElementById("dairy-count").innerHTML = dairy_count;
}

let carbs_count=0;
document.getElementById("carbs-decrease").onclick = function() {
    carbs_count--;
    if (carbs_count<0) {
        carbs_count=0;      // was sugar_count before... costs me 2 marks rip
    }
    document.getElementById("carbs-count").innerHTML = carbs_count;
}
document.getElementById("carbs-increase").onclick = function() {
    carbs_count++;
    document.getElementById("carbs-count").innerHTML = carbs_count;
}

let veg_count=0;
document.getElementById("veg-decrease").onclick = function() {
    veg_count--;
    if (veg_count<0) {
        veg_count=0;
    }
    document.getElementById("veg-count").innerHTML = veg_count;
}
document.getElementById("veg-increase").onclick = function() {
    veg_count++;
    document.getElementById("veg-count").innerHTML = veg_count;
}