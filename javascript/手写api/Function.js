// call

Function.prototype.my_call = function(obj, ...args) {
  obj = obj || window

  const fn = Symbol()
  obj[fn] = this

  const res = obj[fn](...args)
  
  delete obj[fn]
  return res

}

const testobj = {
  name: 'ym',
  testFn(age) {
      console.log(`${this.name}${age}岁了`)
  }
}
const testobj2 = {
  name: 'mason'
}

testobj.testFn.my_call(testobj2, 18) // mason22岁了

