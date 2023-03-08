var rumus = prompt("luas atau keliling?");
var hasil;

while (rumus !== "luas" && rumus !== "keliling") {
    rumus = prompt("luas atau keliling?");
}

var panjang = parseInt(prompt("Masukkan Nilai Panjang: "));
var lebar = parseInt(prompt("Masukkan Nilai Lebar: "));

if (rumus === "luas") {
    hasil = panjang * lebar;
    alert ("Luasnya adalah " + hasil);
} else {
    hasil = 2 * (panjang + lebar);
    alert ("Kelilingnya adalah " + hasil);
}

