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


players.sx_forEach((item, index, arr) => {
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
}

console.log(players.sx_map((item, index) => `${item.name}--${item.num}--${index}`))
// [ '科比--24--0', '詹姆斯--23--1', '保罗--3--2', '威少--0--3', '杜兰特--35--4' ]


// filter

Array.prototype.myFilter = function(callback) {
  let res = []

  for(let i = 0; i < this.length; i++) {
    callback(this[i], i, this) && res.push(this[i])
  }
}

console.log(players.sx_filter(item => item.num >= 23))
// [
//     { name: '科比', num: 24 },
//     { name: '詹姆斯', num: 23 },
//     { name: '杜兰特', num: 35 }
// ]