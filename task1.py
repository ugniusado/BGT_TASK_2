
from bitcoin.rpc import RawProxy

x = RawProxy()

addText = raw_input("Enter transaction id ")

makeTranscationRaw = x.getrawtransaction(addText)

decodedTx = x.decoderawtransaction(makeTranscationRaw)

InputX = 0
OutputX = 0
for input in decodedTx['vin']: #kiek buvo gauta
        idInput = input['txid']
        rawTransaction = x.getrawtransaction(idInput)
        rawTransactionDecode = x.decoderawtransaction(rawTransaction)
        vinOut = input['vout']
        for output in rawTransactionDecode['vout']:
                if(vinOut == output['n']):
                        InputX += output['value']

for output in decodedTx['vout']:
        OutputX += output['value']

print(InputX - OutputX)