const players = [
  { name: '科比', num: 24 },
  { name: '詹姆斯', num: 23 },
  { name: '保罗', num: 3 },
  { name: '威少', num: 0 },
  { name: '杜兰特', num: 35 }
]

// forEach
Array.prototype.myforEach = function (callback) {
  for (let i = 0; i < this.length; i++) {
    callback(this[i], i, this)
  }
}


players.myforEach((item, index, arr) => {
  console.log(item, index)
})
// { name: '科比', num: 24 } 0
// { name: '詹姆斯', num: 23 } 1
// { name: '保罗', num: 3 } 2
// { name: '威少', num: 0 } 3
// { name: '杜兰特', num: 35 } 4


// map

Array.prototype.myMap = function (callback) {
  let res = []

  for (let i = 0; i < this.length; i++) {
    res.push(callback(this[i], i, this))
  }
  return res
}

console.log(players.myMap((item, index) => `${item.name}--${item.num}--${index}`))
// [ '科比--24--0', '詹姆斯--23--1', '保罗--3--2', '威少--0--3', '杜兰特--35--4' ]


// filter

Array.prototype.myFilter = function(callback) {
  let res = []

  for(let i = 0; i < this.length; i++) {
    callback(this[i], i, this) && res.push(this[i])
  }
  return res
}

console.log(players.myFilter(item => item.num >= 23))
// [
//     { name: '科比', num: 24 },
//     { name: '詹姆斯', num: 23 },
//     { name: '杜兰特', num: 35 }
// ]

// every
Array.prototype.myEvery = function(callback) {
  let flag = true

  for(let i = 0; i < this.length; i++) {
    flag = callback(this[i], i, this)
    if(!flag) break
  }

  return flag
}

console.log(players.myEvery(item => item.num >= 23))

// some
Array.prototype.mySome = function(callback) {
  let flag = false

  for(let i = 0; i < this.length; i++) {
    flag = callback(this[i], i, this)
    if(flag) break;
  }

  return flag
}


console.log(players.mySome(item => item.num >= 23)) // true
console.log(players.mySome(item => item.num >= 50)) // false

// reduce

Array.prototype.myReduce = function(callback, ...arg) {
  let start = 0, total;
  if(arg.length) {
    total = arg[0]
  }else {
    pre = this[0];
    start = 1;
  }

  for(let i = start; i < this.length; i++) {
    total = callback(total, this[i], i, this)
  }
  return total
}

const sum = players.myReduce((total, next) => {
  return total + next.num
}, 0)
console.log(sum) // 85

// findIndex
Array.prototype.myFindIndex = function(callback) {
  for(let i = 0; i < this.length; i++) {
    if(callback(this[i], i, this)){
      return i
    }
  }
  return -1;
}

console.log(players.myFindIndex(item => item.name === '科比')) // 0
console.log(players.myFindIndex(item => item.name === '安东尼')) // -1
