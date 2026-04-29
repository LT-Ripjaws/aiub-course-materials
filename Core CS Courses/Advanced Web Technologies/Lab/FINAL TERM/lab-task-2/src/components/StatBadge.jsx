import React from 'react'
import PropTypes from 'prop-types'

function StatBadge({ label, value }) {
  return (
    <span className="stat-badge" data-testid="stat-badge">
      <span className="stat-badge__label">{label}:</span>
      <span className="stat-badge__value">{value}</span>
    </span>
  )
}

StatBadge.propTypes = {
  label: PropTypes.string.isRequired,
  value: PropTypes.oneOfType([PropTypes.string, PropTypes.number]).isRequired,
}
export default StatBadge
