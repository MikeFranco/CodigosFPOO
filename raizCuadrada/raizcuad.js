/* function squareroot(number) {
  var lo = 0, hi = number;
  while(lo <= hi) {
       var mid = Math.floor((lo + hi) / 2);
       if(mid * mid > number) hi = mid - 1;
       else lo = mid + 1;
  }
  return hi;
}

console.log(squareroot(36)); */

function newton(f, fPrime, tolerance) {
  var x, first;

  return function iterate(n) {
    if (!first) { x = n; first = 1; }

    var fn = f(x);

    var deltaX = fn(n) / fPrime(n);
    if (deltaX > tolerance) {
      return iterate(n - deltaX)
    }

    first = 0;
    return n;
  }
}


function f(n) { 
  return  function(x) { 
    if(n < 0) throw n + ' is outside the domain of sqrt()';
    return x*x - n;
  };
}

function fPrime(x) {
  return 2*x;
}


var sqrt = newton(f, fPrime, .00000000001)
console.log(sqrt(1));