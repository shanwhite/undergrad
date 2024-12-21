// calls all the functions listed below when document is opened
document.addEventListener("DOMContentLoaded", () => {
    updatedDefaultMode();           // centralises cells in default mode + yellow background
    defaultMode();                  // doesn't let user input a value that's outside the 0-100 range
    calculateAverage();             // calculates average of assignment results
    storePercentGradeResults();     // stores the original average values to display them later on
    countUnsubmitted();             // counts and displays number of unsubmitted assignments
});

document.addEventListener("DOMContentLoaded", function() {
    // REQUIREMENTS 1 & 2
    var cells = document.querySelectorAll('.grade[contenteditable]');
    cells.forEach(function(cell) {
        // #1(i): automatically updates the average value after user edits cell data
        cell.addEventListener("input", function() {
            calculateAverage();             // calculates average with new values
            storePercentGradeResults();     // stores the new average values
            countUnsubmitted();             // updates unsubmitted assignment count after changing input value
        });
    });

    // REQUIREMENT 3
    document.getElementById("newRowBtn").addEventListener("click", addNewRow);
    document.getElementById("newColBtn").addEventListener("click", addNewCol);
});


// INTERACTIVE REQUIREMENT #1(i)
// calculate final grade average from the assignment columns
function calculateAverage() {
    var table = document.getElementById("table");   // fetch the table from html doc
    var rows = table.rows;                          
    var lastCellIdx = rows[0].cells.length-1;       // index of last cell of row

    // start at index 1 to skip headings
    for (var i=1; i<rows.length; i++) {
        var sum = 0;            // sum of values from the cells (textContent)
        var count = 0;          // counts how many assignments were submitted per row
        var row = rows[i];      // to loop through rows      
        
        // loops through assignment columns
        for (var j=2; j<row.cells.length-1; j++) {
            var cell = row.cells[j];                    // loop through cells of each row (just the assignment columns)
            var value = parseInt(cell.textContent);     // convert textContent string to int

            // if value is valid
            if (value>=0 && value<=100) {
                sum += value;   // add assignment grade to the sum
                count++;        // adds to count (of how many assignments to divide by)
            }
        }

        if (count > 0) {
            var average = Math.round(sum/count);            // requirement #1(i)(a): rounded to nearest whole number
            row.cells[lastCellIdx].textContent = average;   // set cell value as the calculated average

            // #1(i)(a): if below 60%, change to white text and red background
            if (average>=0 && average<60) {
                row.cells[lastCellIdx].style.color = "#fcfbfc";         // white text
                row.cells[lastCellIdx].style.background = "#ed2939";    // red background
            } else {
                // to reset background colour if above 60%
                row.cells[lastCellIdx].style.color = "";
                row.cells[lastCellIdx].style.background = "";
            }
        } else {
            // reset to original
            row.cells[lastCellIdx].textContent = "";
            row.cells[lastCellIdx].style.color = "";
            row.cells[lastCellIdx].style.background = "";
        }
    }
};


// INTERACTIVE REQUIREMENT #1(ii)
// count of assignments not yet submitted
function countUnsubmitted() {
    var unsubmittedCount = 0;              
    var cells = document.querySelectorAll(".grade[contenteditable]");
    // loops through all the cells in the assignment columns
    cells.forEach(function(cell) {
        if (cell.textContent.trim() === "-") {      // trim in case there's spacing before/after the dash
            unsubmittedCount++;                     // add to count
        }
    });
    console.log(unsubmittedCount);                  // log count to console to check
    document.getElementById("unsubmitted-count").textContent = unsubmittedCount;    // display updated count value
};


// INTERACTIVE REQUIREMENT #1(iii)
// if cell is empty, set to default mode of "-"
function updatedDefaultMode() {
    // loops through all the elements in divs with class "grade" & are contenteditable
    document.querySelectorAll(".grade[contenteditable]").forEach(el => {
        if (el.textContent.length == 0) {
            el.textContent = "-";
            el.style.textAlign = "center";      // centralise
            el.style.background = "#fcf4a3";    // yellow background
        }
    });
};

// if input is outside the range of 0 to 100, set to default mode of "-"
function defaultMode() {
    // loops through all the elements in divs with class "grade" & are contenteditable
    document.querySelectorAll(".grade[contenteditable]").forEach(function(cell) {
        cell.addEventListener("input", function() {
            var value = this.textContent.trim();    // cuts away extra spacing
            var inRange = Boolean(parseInt(value)>=0 && parseInt(value)<=100);  // boolean for if the cell value is in the 0-100 range
            if (!inRange) {
                this.textContent = "-";     // set to default if out of range
            }

            // #1(ii): cells containing "-" should be centralised & have yellow background
            if (this.textContent === "-") {
                this.style.textAlign = "center";
                this.style.background = "#fcf4a3";
            } else {
                // to reset alignment and background colour if not "-"
                this.style.textAlign = "right";
                this.style.background = "";
            }
        });
    });
};


// INTERACTIVE REQUIREMENT #2: switch to letter grade / 4.0 scale
// need to double click the first time for it to work...
function changeGrade() {
    var choice = -1;    // -1 to allow 0 to be the first value after clicking (0: Letter Grade, 1: 4.0 Scale)
    document.getElementById("final-grade").onclick = function() {
        choice = (choice+1)%3;    // +1 to move to next switch case, %3 to get it to reset to 0 when choices reaches value 3
        switch(choice) {
            case 0:
                this.textContent = "Average [Letter]";      // this === document.getElementById("final-grade")
                LetterGradeResults();                        // call function to display letter grade values
                break;
            case 1:
                this.textContent = "Average [4.0]";
                GPAScaleResults();                          // call function to display 4.0 scale values
                break;
            default:
                this.textContent = "Average [%]";
                displayPercentGradeResults();               // call function to display percent grade values (back to original)
        }
    }
};

// AMERICAN LETTER GRADE
function LetterGradeResults() {
    var rows = document.getElementById("table").rows;
    // start at index 1 to skip headings
    for (var i=1; i<rows.length; i++) {
        var cells = rows[i].cells;
        var lastCell = parseInt(cells[cells.length-1].textContent);
        var newGrade = cells[cells.length-1];
        // tried to do switch statements but it wasn't working so i switched to if else statements
        if (lastCell >= 93 && lastCell <= 100) {
            newGrade = "A";
        } else if (lastCell >= 90 && lastCell <= 92) {
            newGrade = "A-";
        } else if (lastCell >= 87 && lastCell <= 89) {
            newGrade = "B+";
        } else if (lastCell >= 83 && lastCell <= 86) {
            newGrade = "B";
        } else if (lastCell >= 80 && lastCell <= 82) {
            newGrade = "B-";
        } else if (lastCell >= 77 && lastCell <= 79) {
            newGrade = "C+";
        } else if (lastCell >= 73 && lastCell <= 76) {
            newGrade = "C";
        } else if (lastCell >= 70 && lastCell <= 72) {
            newGrade = "C-";
        } else if (lastCell >= 67 && lastCell <= 69) {
            newGrade = "D+";
        } else if (lastCell >= 63 && lastCell <= 66) {
            newGrade = "D";
        } else if (lastCell >= 60 && lastCell <= 62) {
            newGrade = "D-";
        } else if (lastCell < 60) {
            newGrade = "F";
        } else {
            newGrade = "";
        }
        cells[cells.length-1].textContent = newGrade;           // update the html display with the new average values
        cells[cells.length-1].style.textAlign = "center";       // centralise text since it's not a number
    }
};

// 4.0 SCALE
function GPAScaleResults() {
    var rows = document.getElementById("table").rows;
    // start at index 1 to skip headings
    for (var i=1; i<rows.length; i++) {
        var cells = rows[i].cells;
        var lastCell = cells[cells.length-1].textContent;       // don't need to parseInt because the 4.0 scale references the letter grade content
        var newGrade = cells[cells.length-1];
        if (lastCell === "A") {
            newGrade = "4.0";
        } else if (lastCell === "A-") {
            newGrade = "3.7";
        } else if (lastCell === "B+") {
            newGrade = "3.3";
        } else if (lastCell === "B") {
            newGrade = "3.0";
        } else if (lastCell === "B-") {
            newGrade = "2.7";
        } else if (lastCell === "C+") {
            newGrade = "2.3";
        } else if (lastCell === "C") {
            newGrade = "2.0";
        } else if (lastCell === "C-") {
            newGrade = "1.7";
        } else if (lastCell === "D+") {
            newGrade = "1.3";
        } else if (lastCell === "D") {
            newGrade = "1.0";
        } else if (lastCell === "D-") {
            newGrade = "0.7";
        } else if (lastCell === "F") {
            newGrade = "0.0";
        } else {
            newGrade = "";
        }
        cells[cells.length-1].textContent = newGrade;           // update the html display with the new average values
        cells[cells.length-1].style.textAlign = "center";       // centralise text since it's not a number
    }
};

// PERCENT GRADE
var originalValues = [];
// function to store the original values from percent grade
function storePercentGradeResults() {
    originalValues = [];    // clears the array
    var rows = document.getElementById("table").rows;
    // start from index 1 to skip headings
    for (var i=1; i<rows.length; i++) {
        var cells = rows[i].cells;
        var lastCellValue = cells[cells.length-1].textContent;  // stores it as string because it'll be parsed to integer later on anyway
        originalValues.push(lastCellValue);     // stores the original values (of percent grade) in an array
    }
    console.log(originalValues);
};
// function to display the percent grades (used in changeGrade() function)
function displayPercentGradeResults() {
    var rows = document.getElementById("table").rows;
    // start from index 1 to skip headings
    for (var i=1; i<rows.length; i++) {
        var cells = rows[i].cells;
        cells[cells.length-1].textContent = originalValues[i-1];
        cells[cells.length-1].style.textAlign = "right";
    }
};


// INTERACTIVE REQUIREMENT #3
// #3(i): add new row
function addNewRow() {
    var table = document.getElementById("table");
    var newRow = table.insertRow(-1);           // insert row at the end of the table

    for (var i=0; i<table.rows[0].cells.length; i++) {
        var newCell = newRow.insertCell(i);     // insert cells in each row
        newCell.style.height = "20px";          // set height of each cell so it doesn't appear shrunken after adding

        if (i==0) {                             // if student name column
            newCell.className = "name";
            newCell.contentEditable = true;     // not sure if this is meant to be editable but i'd assume the user would want to add a student's name and id?
        } else if (i==1) {                      // if student id column
            newCell.className = "id";   
            newCell.contentEditable = true;
        } else if (i>=2 && i<table.rows[0].cells.length-1) {    // if assignment column
            newCell.className = "grade";
            newCell.contentEditable = true;
            updatedDefaultMode();               // set default mode of -, centralised, yellow background
            defaultMode();
        } else if (i==table.rows[0].cells.length-1) {           // if final gradecolumn
            newCell.className = "final grade";
            newCell.textAlign = "right";
        }

        countUnsubmitted();         // update the count including new cells
        newCell.addEventListener("input", function() {
            calculateAverage();             // includes new cell values when calculating average
            storePercentGradeResults();     // includes new cell values when storing original results
            countUnsubmitted();             // adds to count upon changing input for a new cell
        });
    }
};

// #3(ii): add new column
function addNewCol() {
    var table = document.getElementById("table");
    var colIdx = table.rows[0].cells.length-1;  // index of the last assignment col, aka 2nd last column

    var newHeaderCell = table.rows[0].insertCell(colIdx);
    newHeaderCell.className = "heading";        // applies same class as the other assignment header cells

    // automatic title allocation
    var newHeading = "Assignment " + (colIdx-1);
    newHeaderCell.textContent = newHeading;
    newHeaderCell.style.background = "#878d91";

    // skips header row and adds new cell to each row (so it adds a column)
    for (var i=1; i<table.rows.length; i++) {
        var newRow = table.rows[i];
        var newCell = newRow.insertCell(colIdx);
        newCell.className = "grade";                // every cell except header is a grade (for each new column)
        newCell.contentEditable = true;             // hence it's content editable
        updatedDefaultMode();                       // default mode of -, centralised, yellow bg
        defaultMode();

        countUnsubmitted();         // update the count including new cells
        newCell.addEventListener("input", function() {
            calculateAverage();             // includes new cell values when calculating average
            storePercentGradeResults();     // includes new cell values when storing original results
            countUnsubmitted();             // adds to count upon changing input for a new cell
        });
    }
};

// missing button for saving and retrieving data