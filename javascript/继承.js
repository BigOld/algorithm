// 博客地址：https://juejin.cn/post/7135069685137506311

// 原型链继承
function Parent1 () {
  this.name = 'parent1'
  this.play = [1, 2, 3]
}

function Child1 () {
  this.type = 'child1'
}

Child1.prototype = new Parent1()
const mason = new Child1()
const jack = new Child1()

mason.play.push(4)
console.log(mason.play)
console.log(jack.play)

// // 构造函数继承

function Parent2 () {
  this.name = 'parent2'
}

Parent2.prototype.getName = function () {
  return this.name
}

function Child2 () {
  Parent2.call(this)
  this.type = 'child2'
}

const kim = new Child2()
console.log(kim) // Child2 { name: 'parent2', type: 'child2' }
console.log(kim.getName()) // TypeError: kim.getName is not a function

// 组合继承

function Parent3 () {
  this.name = 'parent3'
  this.play = [1, 2, 3]
}
Parent3.prototype.getName = function() {
  return this.name
}

function Child3() {
  Parent3.call(this)
  this.type = 'child3'
}

Child3.prototype = new Parent3()

Child3.prototype.constructor = Child3

const a = new Child3()
const b = new Child3()
a.play.push(4)

console.log(a)
console.log(b)
console.log(a.getName())


// // 原型式继承

function object(o) { 
  function F() {}; //临时构造函数
  F.prototype = o; //传入对象o作为临时构造函数的原型对象
  return new F(); //返回临时构造对象实例 
}

let parent4 = {
  name: 'parent4',
  friends: ['p1', 'p2', 'p3'],
  getName: function() {
    return this.name
  }
}

let s1 = Object.create(parent4)
let s2 = Object.create(parent4)

s1.name = 'tom'
s1.friends.push('jerry')

console.log(s1.name) // tom
console.log(s1.friends) // (4) ['p1', 'p2', 'p3', 'jerry']
console.log(s2.friends) // (4) ['p1', 'p2', 'p3', 'jerry']


// // 寄生式继承

let parent5 = {
  name: 'parent5',
  friends: ['p1', 'p2', 'p3'],
  getName: function() {
    return this.name
  }
}

function clone(o) {
  let clone = Object.create(o)
  clone.getFriends = function () {
    return this.friends
  }
  return clone
}

let s3 = clone(parent5)
let s4 = clone(parent5)

s3.name = 'tom'
s4.friends.push('jerry')

console.log(s3.name) // tom
console.log(s3.friends) // (4) ['p1', 'p2', 'p3', 'jerry']
console.log(s4.friends) // (4) ['p1', 'p2', 'p3', 'jerry']


// 寄生组合式继承

function Parent6() {
  this.name = 'parent6'
  this.play = [1, 2]
}

Parent6.prototype.getName = function() {
  return this.name
}

function Child6() {
  Parent6.call(this)
  this.age = 18
}

function inheritPrototype (parent, child) {
  child.prototype = Object.create(parent.prototype) // 减少了组合继承中多进行了一次构造
  // child.prototype.constructor = child
}

inheritPrototype(Parent6, Child6)

Child6.prototype.getFriends = function () {
  return this.friends
}

let jarry = new Child6()
let joy = new Child6()
jarry.play.push(4)
console.log(jarry)
console.log(jarry.getName())
console.log(jarry.play) // (3) [1, 2, 4]
console.log(joy.play) // (2) [1, 2]

