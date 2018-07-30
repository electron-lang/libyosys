const test = require('tape')
const libyosys = require('./')

test('return Hello World', function (t) {
  t.equal(libyosys.hello(), 'Hello World')
  t.end()
})
