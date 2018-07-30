const test = require('tape')
const path = require('path')
const yosys = require('../')

test('libyosys_napi', function (t) {
  yosys.setup()
  // yosys.run(`read_json ${path.resolve(__dirname, 'fail.json')}`)
  yosys.run(`read_json ${path.resolve(__dirname, 'pass.json')}`)
  yosys.run(`write_verilog ${path.resolve(__dirname, 'pass.v')}`)
  yosys.shutdown()

  t.pass()
  t.end()
})
