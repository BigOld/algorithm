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
