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

	$("td").click(function(){
		var id = $(this).attr("id");
	alert(id);
	});

}

function updateGrid(r, c, boardVal) {
	var sel = "#" + r.toString() + "-" + c.toString();
	if(boardVal == 0){
		$(sel).html("Empty");
	} else if (boardVal == 1){
		$(sel).html("1");
	} else if (boardVal == 2){
		$(sel).html("2");
	}else if (boardVal == 3){
		$(sel).html("3");
	}else if (boardVal == 4){
		$(sel).html("4");
	}else if (boardVal == 5){
		$(sel).html("5");
	}else if (boardVal == 6){
		$(sel).html("6");
	}else if (boardVal == 7){
		$(sel).html("7");
	}else if (boardVal == 8){
		$(sel).html("8");
	}else if (boardVal == 9){
		$(sel).html('<img src="bomb.png">');
	}
	// $(sel).
}

$(document).ready(function () {
	$.get("/init", {}, function (response) {
		var data = JSON.parse(response);
		createGrid(data);
		for (var row in data) {
			for (var col in data[row]) {
				updateGrid(row, col, data[row][col]);
			}
		}
	});
});
