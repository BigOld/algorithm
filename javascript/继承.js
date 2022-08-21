
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