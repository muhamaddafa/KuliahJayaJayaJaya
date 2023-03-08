var batas = prompt ("Masukkan Batas: ");

for (var i = 2; i <= batas; i++) {
    var check = 1;

    for (var j = 2; j < i; j++) {
        if (i % j === 0) {
           check = 0;
        }
    }

    if (i > 1 && check == 1) {
        document.write(i + "<br>");
    }
}