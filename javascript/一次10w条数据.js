// 通过setTimeOut
const container = document.getElementById('container')

const renderList = async () =>{
  const list = await getList()

  const total = list.length
  const page = 0

  const limit = 200

  const totalPages = Math.ceil(total / limit)

  const render = (page) => {
    if(page === totalPages) return
    setTimeout(() => {
      for(let i = page * limit; i < page * limit + limit; i++) {
        const item = list[i]
        const div = document.createElement('div')
        div.innerHTML = `<img src="${item.src}"/><span>${item.text}</span>`
        container.appendChild(div)
      }
      render(page + 1)
    }, 0)
  }
  render(page)
  console.timeEnd('时间列表')
}

// 高效一点的requestAnimationFrame + 文件碎片
// requestAnimationFrame来替换setTimeOut, 文件碎片来减少dom操作

const renderList2 = async() => {
  const list = await getList()
  const total = list.length
  const page = 0

  const limit = 200

  const totalPage = Math.ceil(total / limit)

  const render = (page) => {
    if(page === totalPage) return
    requestAnimationFrame(() => {
      // 创建文档碎片
      const fragment = document.createDocumentFragment()
      for(let i = page * limit; i < page * limit + limit; i++) {
        item = list[i]
        const div = document.createElement('div')
        div.innerHTML = `<img src="${item.src}"/><span>${item.text}</span>`
        fragment.appendChild(div)
      }
      // 一次性appendChild
      container.appendChild(fragment)
      render(page)
    })
  }
  render(page)
}
