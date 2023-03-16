function dapetJumlah() {
	var jumlah = document.getElementById("floatingInput jumlah").value;
	var myForm = document.getElementById("myForm");
	while (myForm.hasChildNodes()) {
		myForm.removeChild(myForm.firstChild);
	}
	var judul = document.createElement("h3");
	judul.setAttribute("id", "heading");
	var textJudul = document.createTextNode("Anggota Kelompok:");
	judul.appendChild(textJudul);
	myForm.appendChild(judul);

	for (let i = 0; i < jumlah; i++) {
		// Element form
		var form = document.createElement("div");
		form.setAttribute("class", "form-floating");
		form.setAttribute("id", "form-kelompok");

		// Node form: Input
		var input = document.createElement("input");
		input.setAttribute("type", "text");
		input.setAttribute("class", "form-control");
		input.setAttribute("id", "floatingInput");
		input.setAttribute("placeholder", "Nama Anggota");

		// Node form: label
		var label = document.createElement("label");
		var a = document.createTextNode("Nama Anggota " + (i + 1));
		label.setAttribute("for", "floatingInput");
		label.appendChild(a);

		var br = document.createElement("br");
		form.appendChild(input);
		form.appendChild(br.cloneNode());
		form.appendChild(label);

		myForm.appendChild(form);
	}

	// Button
	var button = document.createElement("button");
	var btntext = document.createTextNode("Submit Kelompok");
	button.appendChild(btntext);
	button.setAttribute("type", "button");
	button.setAttribute("class", "btn btn-primary");
	myForm.appendChild(button);
}
