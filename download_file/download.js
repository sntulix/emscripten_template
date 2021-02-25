function download(filenamePtr, dataPtr, size) {
  const a = document.createElement('a')
  a.style = 'display:none'
  document.body.appendChild(a)
//  const view = new Uint8Array(Module.HEAPU8.buffer, dataPtr, size) // from EM_ASM()
  view = dataPtr // In case of javascript string
  const blob = new Blob([view], {
      type: 'octet/stream'
  })
  const url = window.URL.createObjectURL(blob)
  a.href = url
//  const filename = UTF8ToString(filenamePtr) // from EM_ASM()
  const filename = filenamePtr // In case of javascript string
  a.download = filename
  a.click()
  window.URL.revokeObjectURL(url)
  document.body.removeChild(a)
}
window.download = download
