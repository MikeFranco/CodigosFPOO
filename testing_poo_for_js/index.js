/* 
let createNewPerson2 = name => {
  let obj = {};
  obj.name = name;
  obj.saludo = () => console.log(`Hola ${this.name} un gusto`);
}

let aver = new createNewPerson2('Mike');
aver.name;
aver.saludo(); */

/* function createNewPerson(name) {
  var obj = {};
  obj.name = name;
  obj.greeting = function() {
    console.log(`Hola ${obj.name}, mucho gusto`);
  };
  return obj;
}

var mike = createNewPerson('Mike');
mike.name;
mike.greeting();
 */

/* 
const a = 10;
let b = a;
b = 20;
console.log(b) */

/* let a = ['hola', 'puñetas'];
let b = [...a];
b.splice(0,1)
//b = [];

console.log(a);
console.log(b);

 */

//const a = algo.reduce((carry, el, index, arr) => ,0)

const algoChido = [
    {
        "name": "Myrna Morones Mendoza",
        "id": 247,
        "balance": 0,
        "deposits": 667613.57,
        "payments": 1482186.19,
        "bonus": 0,
        "yield_value": 84574.52703988396,
        "yield_vat_value": 4433.6145428400005,
        "yield_plus_vat": 89008.14158148001,
        "withdraws": 100,
        "commission_vat_value": 506.5725512850001,
        "commission": 3166.078445469,
        "total_commission": 3672.650996754,
        "active_capital": 0,
        "AUM": 752849.060584726
    },
    {
        "realEstate": 2,
        "pymes": 2,
        "factoring": 20,
        "exclusives": 24,
        "events": 10
    }
]

const res = algoChido.reduce((carry, el) => ({ ...carry,  ...el }),{})

console.log(res)

