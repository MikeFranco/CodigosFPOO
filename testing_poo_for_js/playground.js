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
.then(resObject => cosaPromise(2000, resolve => { 
    const MATH = Math.random()*10+1;
    resolve(MATH);
    console.log(MATH);
}))
.then(randomRes => cosaPromise(1000, (resolve, reject) => randomRes > 5 ? resolve('yei') : reject('Buu')))
.then(stringResult => cosaPromise(500, resolve => {resolve('Soy la vrg'); console.log(stringResult)}))
.then(vrgString => console.log(vrgString))
.catch(err => console.error(err));





/* const panel = 
[
  {
      "name": "Myrna Morones Mendoza",
      "id": 247,
      "balance": 0,
      "deposits": 667613.57,
      "payments": 1475986.19,
      "bonus": 6200,
      "yield_value": 78958.81195797396,
      "yield_vat_value": 3535.1001296960003,
      "yield_plus_vat": 82493.91208578002,
      "withdraws": 100,
      "commission_vat_value": 470.6319747570001,
      "commission": 2941.4498421390003,
      "total_commission": 3412.0818168960004,
      "AUM": 752795.400268884
  },
  {
      "realEstate": 2,
      "pymes": 2,
      "factoring": 20,
      "exclusives": 24,
      "events": 10
  },
  {
      "active_investments": 11,
      "closed_investments": 27,
      "in_process_investments": 0,
      "rejected_investments": 0,
      "in_founding_investments": 0,
      "completed_investments": 0
  },
  {
      "calculate_balance": 6144.078480104217
  },
  {
      "amount_in_founding": 48768.66
  },
  [
      {
          "717": 1272628.2000000002,
          "id": 702,
          "yield_rate": 20,
          "amount_invested": 60000,
          "capital": 24649.21,
          "active_capital": 35350.79
      },
      {
          "id": 717,
          "yield_rate": 20,
          "amount_invested": 108000,
          "capital": 44368.59,
          "active_capital": 63631.41
      },
      {
          "id": 1689,
          "yield_rate": 14,
          "amount_invested": 5000,
          "capital": 0,
          "active_capital": 5000
      },
      {
          "id": 1930,
          "yield_rate": 17,
          "amount_invested": 224000,
          "capital": 11393.49,
          "active_capital": 212606.51
      },
      {
          "id": 2269,
          "yield_rate": 17,
          "amount_invested": 768842.06,
          "capital": 35717.44,
          "active_capital": 733124.6199999999
      },
      {
          "id": 2750,
          "yield_rate": 16,
          "amount_invested": 513719.43,
          "capital": 0,
          "active_capital": 513719.43
      }
  ]
]


const arrayToObject = (array, keyField) =>
   array.reduce((obj, item) => {
     obj[keyField] = item
     return obj
   }, {})

const aNewPanel = panel.reduce((carry, el)=> ({...carry, ...el}),{})
const onlyUserInfo = panel.reduce((carry, el) => carry['userInfo'] = el,{})
//const pan = aNewPanel.reduce((carry, el) => carry['algo'] = el ,{})
//const newPanel = arrayToObject(panel, 'userPanelInfo')
//const panelMerge = newPanel.userPanelInfo.reduce((carry, el)=> ({...carry, ...el}),{})
//console.log(aNewPanel)
console.log(onlyUserInfo)
 */