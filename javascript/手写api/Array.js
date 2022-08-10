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


// find
Array.prototype.myFind = function(callback) {
  for(let i = 0; i < this.length; i++) {
    if(callback(this[i], i, this))
      return this[i]
  }
  return undefined
}


console.log(players.myFind(item => item.name === '科比')) // { name: '科比', num: 24 }
console.log(players.myFind(item => item.name === '安东尼')) // undefined

// fill
Array.prototype.myFill = function(value, start = 0, end) {
  end = end || this.length
  for(let i = start; i < end; i++) {
    this[i] = value
  }
  return this
}

console.log(players.myFill('mason', 1, 3))

// includes

Array.prototype.myIncludes = function(el, index = 0) {
  if(start < 0) start = this.length + start
  if(el.toString() === 'NaN') el = 'NaN'
  for(let i = index; i < this.length; i++) {
    if(this[i] === el || this[i].toString() === 'NaN') 
      return true
  }
  return false
}

console.log([1, 2, 3].myIncludes(2)) // true
console.log([1, 2, 3, NaN].myIncludes(NaN)) // true
console.log([1, 2, 3].myIncludes(1, 1)) // false


// join

Array.prototype.myJoin = function(sep = ',') {
  let str = ''

  for(let i = 0; i < this.length; i++) {
    str += i === 0 ?  `${this[i].toString()}` : `${sep}${this[i].toString()}`
  }

  return str
}

console.log([1, 2, 3].myJoin()) // 1,2,3
console.log([1, 2, 3].myJoin('*')) // 1*2*3