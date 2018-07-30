const test = require('tape')
const libyosys = require('./')

test('libyosys_napi', function (t) {
  t.equal(libyosys.hello(), 'Hello World')
  t.equal(libyosys.add(2, 3), 5)
  t.end()
})
