from flask import Flask, jsonify,request, render_template
app = Flask(__name__)

@app.route("/",methods=['GET'])
def home():
    message = "Hello API"
    return("hello from api")
    #return render_template("base.html",message = message)

@app.route("/sum/<int:n>/<int:m>",methods=['GET'])
def sum_api(n,m):
    sum = n+m
    return ("sum = "+str(sum))

@app.route("/data/<string:id>",methods=['GET'])
def nums(id):
    return("hello "+id)

if __name__ == '__main__':
    app.run(debug=True)