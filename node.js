let count = 0;

(function countUp() {
    if (count === 3) return;
    count++;
    setTimeout(countUp, 1000);
    console.log(count);
})()

console.log(count)