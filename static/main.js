function createGrid(data) {
	var result = "";

	for (var i in data) {
		var cr = "<tr>";

		for (var j in data[i]) {
			cr = cr + "<td id=\"" + i.toString() + "-" + j.toString() + "\"></td>"
		}

		cr = cr + "</tr>\n";
		result = result + cr;
	}

	$("#grid").html(result);

	$("td").click(function () {
		var id = $(this).attr("id");

		var x = id[0];
		var y = id[2];
		// alert(x + " and " + y);
		var location = { "x": x, "y": y, "btn": "left" };
		$.get("/handle", location, function (response) {
			var data = JSON.parse(response);
			updateGrid(data);
		});
	});

	$("td").contextmenu(function (e) {
		e.preventDefault();
		var id2 = $(this).attr("id");
		var x = id2[0];
		var y = id2[2];
		// alert("Right clicked for " + x + " and " + y);
		var location = { "x": x, "y": y, "btn": "right" };
		$.get("/handle", location, function (response) {
			var data = JSON.parse(response);
			var board = data["board"];
			updateGrid(data);
		});
	});
}

function updateGrid(data) {
	var board = data["board"];
	var terminateState = data["state"];
	if (terminateState == true) {
		var row;
		var col;
		for (row in board) {
			for (col in board[row]) {
				var sel = "#" + row.toString() + "-" + col.toString();
				var x = parseInt(row);
				var y = parseInt(col);
				if (board[x][y] == "Explode") {
					$(sel).html('<img src="explode.jpeg">');
				}
			}
		}
		alert("Game Over!");
	} else {
		var row;
		var col;
		for (row in board) {
			for (col in board[row]) {
				var sel = "#" + row.toString() + "-" + col.toString();
				var x = parseInt(row);
				var y = parseInt(col);
				if (board[x][y] == "Empty") {
					$(sel).html("Empty");
				} else if (board[x][y] == "1") {
					$(sel).html("1");
				} else if (board[x][y] == "2") {
					$(sel).html("2");
				} else if (board[x][y] == "3") {
					$(sel).html("3");
				} else if (board[x][y] == "4") {
					$(sel).html("4");
				} else if (board[x][y] == "5") {
					$(sel).html("5");
				} else if (board[x][y] == "6") {
					$(sel).html("6");
				} else if (board[x][y] == "7") {
					$(sel).html("7");
				} else if (board[x][y] == "8") {
					$(sel).html("8");
				} else if (board[x][y] == "Bomb") {
					$(sel).html('<img src="bomb.png">');
				} else if (board[x][y] == "Flag") {
					$(sel).html('<img src="flag.png">');
				} else if (board[x][y] == "Covered") {
					$(sel).html('<img src="cover.png">');
				}
			}
		}
	}

}

$(document).ready(function () {
	//Disable right click context menu
	// $('body').attr('oncontextmenu', 'return false;')

	$.get("/init", {}, function (response) {
		var data = JSON.parse(response);
		createGrid(data["board"]);
		updateGrid(data);

	});

});
