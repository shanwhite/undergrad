// initial references to html
const red = document.querySelector('#red');
const yellow = document.querySelector('#yellow');
const green = document.querySelector('#green');
const blue = document.querySelector('#blue'); 

// new variables
var order=[];           // to keep track of order of buttons flashed
var playerOrder=[];     // to keep track of order of buttons player clicked on
var currentScore = 0;   // current round 
var highScore = 0;      // best score recorded
var check=true;         // check if player is right or wrong
var i=0;                // index

// effects from clicking on start button
document.querySelector('.start').addEventListener('click', function() {
    document.querySelector('#status').style.background = "#50c878"; // status changes from red to green
    setTimeout(startGame, 3000);    // 3000ms = 3s delay before the game begins
});

// game begins
function startGame() {
    currentScore=0;     // reset score, or start from zero (first game)
    check=true;
    order=[];           // empty the order array
    playerOrder=[];     // empty the playerOrder array
    flashColors();      // call the function to flash colors
}

// when player clicks on the circles
var colouredCircles = document.querySelectorAll(".coloured");
colouredCircles.forEach(function(circle) {
    // upon clicking each button
    circle.addEventListener("click", function() {
        // adds to playerOrder array (what the player clicked)
        // circle.id will save as the colour but the order array uses numbers
        // easier to compare numbers so changed playerOrder array to numbers
        if (circle.id=="red") {
            playerOrder.push(0);
        } else if (circle.id=="yellow") {
            playerOrder.push(1);
        } else if (circle.id=="green") {
            playerOrder.push(2);
        } else if (circle.id=="blue") {
            playerOrder.push(3);
        }

        // compares playerOrder and order arrays to see if they match
        if (playerOrder[i]===order[i]) {
            console.log(i + " is correct", order, playerOrder);
            i++;
        } else {
            console.log(i + " is wrong", order, playerOrder);
            check = false;
            lose();
        }  
    });
});

// function for flashing colors
async function flashColors() {
    // while the game is still running (i.e. player hasn't made any wrong moves)
    while (check) {
        let colors = [red, yellow, green, blue];    // initialise color array
        let num = Math.floor((Math.random()*colors.length));    // generates 0, 1, 2 or 3 randomly
        order.push(num);    // adds the number to the order array

        // refresh the playerOrder array and index
        playerOrder=[];
        i=0;

        // flashing colors generated
        for(var j=0; j<order.length; j++) {
            // system picks red
            if (order[j]==0) {
                // red.style.background = "#ff474c";
                red.style.background = "white";
                console.log("red");
                clearColors();  // calls function that sets color back to default + delay of 3s
            } 
            // system picks yellow
            else if (order[j]==1)  {
                // yellow.style.background = "#fff157";
                yellow.style.background = "white";
                console.log("yellow");
                clearColors();
            } 
            // system picks green
            else if (order[j]==2)  {
                // green.style.background = "#aaf0c9";
                green.style.background = "white";
                console.log("green");
                clearColors();
            } 
            // system picks blue
            else if (order[j]==3)  {
                // blue.style.background = "#add8e6";
                blue.style.background = "white";
                console.log("blue");
                clearColors();
            }

            // speeding up intervals after 5th, 9th, 13th rounds
            if (order.length >= 0 && order.length < 5) {
                await delay(1000);
            } else if (order.length >= 5 && order.length < 9) {
                await delay(800);
            } else if (order.length >= 9 && order.length < 13) {
                await delay(600);
            } else if (order.length >= 13) {
                await delay(400);
            }
        }

        // if check is true, i.e. if the player is correct
        if (check) {
            // if user takes more than 5 seconds
            await delay(5000);
            // if user doesn't click all colors in time
            if(playerOrder.length<order.length) {
                // game over
                check=false;
                lose();
            }
            currentScore++;
        }
        
        // record the latest score
        // add '0' to the front if single digit
        if (currentScore<10) {
            document.getElementById("latest").innerHTML = "0" + currentScore;
        } else {
            document.getElementById("latest").innerHTML = currentScore;
        }

        // if the current score is higher than the high score
        // set current score as the new high score
        if (currentScore>highScore) {
            if (currentScore<10) {
                document.getElementById("best").innerHTML = "0" + currentScore;
            } else {
                document.getElementById("best").innerHTML = currentScore;
            }
        }
    }
};

// reset circle color to default
function clearColors() {
    setTimeout(() => {
        red.style.background = "";
        yellow.style.background = "";
        green.style.background = "";
        blue.style.background = "";
    }, 300);
};

// if the user loses
async function lose() {
    // changes status back to red
    document.querySelector('#status').style.background = "#ff0800";
    
    var k = 0;
    // while loop to flash all circles 5 times
    while (k<5) {
        // flashes button
        red.style.background = "white";
        yellow.style.background = "white";
        green.style.background = "white";
        blue.style.background = "white";

        await delay(500);

        // resets to default colour
        red.style.background = "";
        yellow.style.background = "";
        green.style.background = "";
        blue.style.background = "";

        await delay(500);

        k++;
    }
};

// offset time / add delay
function delay(time) {
  return new Promise(function(resolve, reject){
    setTimeout(function(){
      // does nothing
      resolve();
    },time);
  });
}