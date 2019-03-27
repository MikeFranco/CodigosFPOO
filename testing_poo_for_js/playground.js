/* 
setInterval((function() {  
  return console.log('I\'m Batman!');
}), 1000);

setTimeout((function() {  
    return process.kill(process.pid);
}), 5000);

 */

const cosaPromise = (duration, callback) => new Promise((resolve, reject) => setTimeout(() => callback(resolve, reject), duration));

cosaPromise(3000, resolve => resolve({ msg: 'hola', num: 3 }))
.then(resObject => cosaPromise(2000, resolve => resolve(Math.random()*10+1)))
.then(randomRes => cosaPromise(1000, (resolve, reject) => randomRes > 5 ? resolve('yei') : reject('Buu')))
.then(stringResult => cosaPromise(500, resolve => resolve('Soy la vrg')))
.then(vrgString => console.log(vrgString))
.catch(err => console.error(err));
