async function asyncPool(poolLimit, array, iteratorFn) {
  const ret = [] // 存储的所有异步任务
  const executing = [] // 正在执行的异步任务

  for(const item of array) {
    const p = Promise.resolve().then(() => iteratorFn(item, array)) // 这里是异步任务，要先执行完同步才会执行then
    ret.push(p)

    if(poolLimit <= array.length) { // 任务多于限制时进行并发控制
      const e = p.then(() => executing.splice(executing.indexOf(e), 1))
      executing.push(e)
    }
    if(poolLimit <= executing.length) { // 进行的任务多于限制时，进行等待
      await Promise.race(executing) // race 等待较快的任务执行完成
    }
  }

  return Promise.all(ret)
}

