var batas = prompt("Masukkan Batas Akhir: ");

for (var i = 1; i<=batas; i++) {
    if (i % 2 !== 0) {
        document.write(i + "<br>");
    }
}