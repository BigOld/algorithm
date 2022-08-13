const obj = {
  name: 'mason',
  age: 18,
  gender: '男'
}

// entries

// 排列与使用 for...in 循环遍历该对象时返回的顺序一致
// 区别在于 for-in 循环还会枚举原型链中的属性
Object.prototype.my_entries = function(obj) {
  let res = []
  for(let key in obj) {
    obj.hasOwnProperty(key) && res.push([key, obj[key]])
  }
  return res;
}

console.log(Object.my_entries(obj))

// formEntries
// 将键值对数组转换为对象 与 entries 相反
Object.prototype.my_formEntries = function(arrs) {
  let obj = {}
  for(let arr of arrs) {
    const [key, value] = arr
    obj[key] = value
  }
  return obj
}

console.log(Object.my_formEntries([['name', 'mason'], ['age', 18], ['gender', '男']]))

// keys

Object.prototype.my_keys = function(obj) {
  let res = []
  for(let key in obj){
    obj.hasOwnProperty(key) && res.push(key)
  }
  return res
}

console.log(Object.my_keys(obj))

// values

Object.prototype.my_values = function(obj) {
  let res = []
  for(let key in obj){
    obj.hasOwnProperty(key) && res.push(obj[key])
  }
  return res
}

console.log(Object.my_values(obj))

// instanceof
// 判断parent 是否在 child 的原型链上

function instanceOf(father, child) {
  let fp = father.prototype
  let cp = child.__proto__

  while(cp) {
    if(cp === fp)
      return true
    cp = cp.__proto__
  }
  return false
}

// test
function Person(name) {
  this.name = name
}

let mason = new Person('mason')
let jack = {
  name: 'jack'
}

console.log(instanceOf(Person, mason)) // true
console.log(instanceOf(Person, jack)) // false


// is

Object.prototype.my_is = function(x, y) {
  if(x === y) {
    return x !== 0 || 1 / x === 1 / y // 防止 -0 和 +0
  }
  // 一个变量不等于自身变量,那么它一定是 NaN
  // 两个都是NaN的时候返回true
  return x !== x && y !== y
}

const a = { name: 'mason' }
const b = a
const c = { name: 'mason' }
console.log(Object.my_is(a, b)) // true
console.log(Object.my_is(a, c)) // false
console.log(Object.my_is(NaN, NaN)) // true
console.log(Object.my_is(-0, +0)) // false

// assign

Object.prototype.my_assign = function(target, ...args) {
  if(target === null || target === undefined) {
    throw new TypeError('Cannot convert undefined or null to object')
  }

  target = Object(target) // 防止传进来不是对象

  for(let arg of args) {
    for(let key in arg) {
      arg.hasOwnProperty(key) && (target[key] = arg[key])
    }
  }
  return target
}
const testa = { name: 'mason' }
const testb = { name: 'jack', age: 22 }
const testc = { age: 18, gender: '男' }

const testd = Object.my_assign(testa, testb, testc)
console.log(testd) // { name: 'jack', age: 18, gender: '男' }
console.log(testa === testd) // true