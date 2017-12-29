function processData(input) {
    const div = 1000000000;
    var numbers = input.split(/[ ,,\n]+/);
    var u = parseFloat(numbers[0]);
    var b = parseFloat(numbers[1]);

    var prev_x, x, next_x;
    x = u;

    for(i=1; i<div; ++i) {
      next_x = Math.floor(Math.pow(2, b-x*x)) / div;
      if((i>1) && (Math.abs(next_x - x) < 0.000000001 || Math.abs(next_x - prev_x) < 0.000000001 )) {
        console.log((x + next_x).toFixed(9));
        return;
      }

      prev_x = x;
      x = next_x;
    }

    console.log(-1);
}

process.stdin.resume();
process.stdin.setEncoding("ascii");
_input = "";
process.stdin.on("data", function (input) {
    _input += input;
});

process.stdin.on("end", function () {
   processData(_input);
});
