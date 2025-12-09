import { DataTypes } from "sequelize";
import conectDB from "../../config/db.js";
import Object from "../object/object.model.js";
import Person from "../person/person.model.js";

const sequelize = await conectDB();
const Loan = sequelize.define("Loans",{
   id: {type: DataTypes.INTEGER, primaryKey: true, autoIncrement: true, allowNull: false},
   loanDate:{type: DataTypes.DATEONLY, allowNull: false},
   repaymentDate: {type: DataTypes.DATEONLY, allowNull: false},
   itIsBack:{type: DataTypes.BOOLEAN, allowNull: false, defaultValue: false},
   status: {type: DataTypes.STRING, allowNull: false, defaultValue: "pending"},
   notes: {type: DataTypes.STRING, allowNull: true},
   personId: {type: DataTypes.INTEGER, allowNull: false, references: {model: Person, key: 'id'}},
   objectId: {type: DataTypes.INTEGER, allowNull: false, references: {model: Object, key: 'id'}},
});

Person.belongsToMany(Object, {through: Loan})
Object.belongsToMany(Person, {through: Loan})

Loan.belongsTo(Person)
Person.hasMany(Loan)
Loan.belongsTo(Object)
Object.hasMany(Loan)

await Loan.sync();
export default Loan;