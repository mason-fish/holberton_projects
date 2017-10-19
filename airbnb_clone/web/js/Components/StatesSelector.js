import React, {Component} from 'react';
import StateItemSelector from 'js/Components/StateItemSelector';

// will be a list of components
export default class StatesSelector extends Component {
    constructor(props) {
        super(props);
    }

    componentDidMount() {
        this.props.fetchStates();
    }

    createStateList() {
        if (!this.props.states) {
            return <div>Loading...</div>;
        }
        return (this.props.states.map((each) => {
            <li key={each.id}>
                Okay!
                {console.log(each.name)}
                {each.name}
            </li>
        }));
    }

    render () {  
        return (
            <div>
                <h1>States:</h1>
                <ul>
                    {this.createStateList()}
                </ul>
            </div>
        );
    }
}

StatesSelector.propTypes = {
  fetchStates: React.PropTypes.func,
  states: React.PropTypes.array,
};

//<StateItemSelector key={each.id} name={each.name} />