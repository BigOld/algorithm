// 浅拷贝

function shallowClone(obj) {
  let res = new Object()
  for(let key in obj) {
    res[key] = obj[key]
  }
  return res;
}

const sa = { name: 'sunshine_lin', age: 23, arr: [] }
const sb = shallowClone(a)

console.log(a, b, a === b)


// 深拷贝

function deepClone(target, map = new Map()) {
  if(typeof target !== 'object'){
    return target
  }

  const temp = Array.isArray(target) ? [] : {}
  
  if(map.get(target)) {
    return map.get(target)
  }

  map.set(target, temp)

  for(let key in target) {
    temp[key] = deepClone(target[key], map)
  }

  return temp
}

const a = {
  name: 'sunshine_lin',
  age: 23,
  hobbies: { sports: '篮球', tv: '雍正王朝' },
  works: ['2020', '2021']
}
a.key = a // 环引用
const b = deepClone(a)

console.log(b)