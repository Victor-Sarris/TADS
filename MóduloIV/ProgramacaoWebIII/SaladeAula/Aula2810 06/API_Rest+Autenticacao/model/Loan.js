import { BOOLEAN, DataTypes, DATE, INTEGER, STRING } from "sequelize";
import conectDB from "../database/db.js";
import Object from "./Objects.js";
import Person from "./Person.js";

const sequelize = await conectDB();

const Loan = sequelize.define("Loans", {
  person: { type: DataTypes.STRING, allowNull: false },
  objetoId: { type: DataTypes.STRING, allowNull: false },
  loanDate: { type: DataTypes.STRING, allowNull: false },
  repaymentDate: { type: DataTypes.DATEONLY, allowNull: false },
  itIsBack: { type: DataTypes.DATEONLY, allowNull: false, defaultValue: false },
  id: {type: DataTypes.INTEGER, primaryKey: true, autoIncrement: true, allowNull: false },
});

Person.belongsTo(Object, { through: Loan });
Object.belongsTo(Person, { through: Loan });

Loan.belongsTo(Person);
Person.hasMany(Loan);
Loan.belongsTo(Object);
Object.hasMany(Loan);

await Loan.sync();
export default Loan;
